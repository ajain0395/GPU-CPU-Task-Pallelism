#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <memory>
#include <stdlib.h>
#include "cotton.h"
#include <sys/time.h>

#define __CL_ENABLE_EXCEPTIONS

#include <CL/cl.hpp>
//#include"hclib_cpp.h"

float* CMATCPU = NULL;
volatile int *atomic;
void gpukernel(float *AMAT, float *BMAT, float *CMAT,int ROW,int COL,float offload)
{
    unsigned int platform_id=0, device_id=0;
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);

    // Get a list of devices on this platform
    std::vector<cl::Device> devices;
    platforms[platform_id].getDevices(CL_DEVICE_TYPE_GPU|CL_DEVICE_TYPE_CPU, &devices); // Select the platform.

    // Create a context
    cl::Context context(devices);

    // Create a command queue
    cl::CommandQueue queue = cl::CommandQueue( context, devices[device_id],CL_QUEUE_PROFILING_ENABLE);   // Select the device.

    // Create the memory buffers
    cl::Buffer bufferA=cl::Buffer(context, CL_MEM_READ_ONLY, ROW * COL * sizeof(float));
    cl::Buffer bufferB=cl::Buffer(context, CL_MEM_READ_ONLY, ROW * COL * sizeof(float));
    cl::Buffer bufferC=cl::Buffer(context, CL_MEM_WRITE_ONLY, ROW * COL * sizeof(float));

    // Copy the input data to the input buffers using the command queue.
    queue.enqueueWriteBuffer( bufferA, CL_FALSE, 0, ROW * COL * sizeof(float), AMAT );
    queue.enqueueWriteBuffer( bufferB, CL_FALSE, 0, ROW * COL * sizeof(float), BMAT );


    // Read the program source
    std::ifstream sourceFile("mymatrixkernel.cl");

    std::string sourceCode( std::istreambuf_iterator<char>(sourceFile), (std::istreambuf_iterator<char>()));
    cl::Program::Sources source(1, std::make_pair(sourceCode.c_str(), sourceCode.length()));

    // Make program from the source code
    cl::Program program=cl::Program(context, source);

    // Build the program for the devices
    program.build(devices);

    // Make kernel
    cl::Kernel vecadd_kernel(program, "matrixVectorMul");

    // Set the kernel arguments
    vecadd_kernel.setArg( 0, bufferA );
    vecadd_kernel.setArg( 1, bufferB );
    vecadd_kernel.setArg( 2, bufferC );
    vecadd_kernel.setArg( 3, ROW);
    vecadd_kernel.setArg( 4, COL);


    // Execute the kernel
    cl::NDRange global( (int)(ROW  * offload));
    std::cout<<(int)(ROW  * offload)<<" OFFLOAD\n";
//        cl::NDRange local( 256 );
    cl::Event evt;
    queue.enqueueNDRangeKernel(vecadd_kernel, cl::NullRange, global,cl::NullRange,NULL,&evt);

    //queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(512), cl::NullRange, NULL, &evt);
    evt.wait();
    long elapsed = evt.getProfilingInfo<CL_PROFILING_COMMAND_END>() - evt.getProfilingInfo<CL_PROFILING_COMMAND_START>();

    // Copy the output data back to the host
    queue.enqueueReadBuffer( bufferC, CL_TRUE, 0, ROW*COL * sizeof(float), CMAT);
   std::cout<<"\nGPU TIME: "<<(float)elapsed/1000000000<<" seconds\n";
}
typedef struct matrix_data_
{
    float *A;
    float *B;
    float *C;
    int row;
    int col;
    int index;
}mat_data_t;
void rowwise( float* matrixA,   float* vectorB,  float* resultVector, int row,int col,int index)
{
    int index2 = (index * col);
    float value = 0;
    std::cout<<" rowwise async"<<std::endl<<col<<" COL "<< row<<" ROW";

    for(int j = 0;j < col;j++)
    {
        value = 0;
        for (int k = 0; k < row;k++)
        {
            value += (matrixA[index2 + k] * vectorB[(k * row) + j]);
        }
        resultVector[index2 + j] = value;
       // std::cout<<" ["<<index2 + j<<"]: "<<CMATCPU[index2 + j]<<"\n";
    }
}

void rowwise(mat_data_t *mat)
{
    int index2 = (mat->index * mat->col);
    float value = 0;
  //  std::cout<<" rowwise async"<<std::endl<<col<<" COL "<< row<<" ROW";

    for(int j = 0;j < mat->row;j++)
    {
        value = 0;
        for (int k = 0; k < mat->row;k++)
        {
            value += (mat->A[index2 + k] * mat->B[(k * mat->row) + j]);
        }
        mat->C[index2 + j] = value;
        // std::cout<<" ["<<index2 + j<<"]: "<<CMATCPU[index2 + j]<<"\n";
    }
}

void cpukernel(float *AMAT, float *BMAT, float *CMAT,int ROW,int COL,float offload)
{
//    std::cout<<"In CPU async"<<std::endl<<COL<<" COL "<< ROW<<" ROW";
  //  std::cout<<"out add: "<<AMAT<<std::endl;
   // int rowi = ;

    for (int i = (int)(ROW * offload); i < ROW;i++)
    {
//        mat_data_t *matdata = new mat_data_t;
//        matdata->A = AMAT;
//        matdata->B = BMAT;
//        matdata->C = CMAT;
//        matdata->index = i;

     // cotton::async([=]() {
            rowwise(AMAT, BMAT, CMAT, ROW, COL, i);
     //   });

//     cotton::async([=](){
////            std::cout<<"In CPU async"<<std::endl<<COL<<" COL "<< ROW<<" ROW";
//        std::cout<<"in add: "<<AMAT<<std::endl;
//
//          int index2 = (i * COL);
//          float value = 0;
//          for(int j = 0;j < COL;j++)
//          {
//              value = 0;
//              for (int k = 0; k < ROW;k++)
//              {
//                  value += (AMAT[index2 + k] * BMAT[(k * ROW) + j]);
//              }
//              CMATCPU[index2 + j] = value;
//              std::cout<<"Val: "<<value<<std::endl;
////              std::cout<<"Hello ["<<index2 + j<<"]: "<<CMATCPU[index2 + j]<<"\n";
//          }
//
//      });
    }
}
void mydelete(float *ptr)
{
    if(ptr == NULL)
    {
        delete(ptr);
    }
}
int max(int a,int b)
{
    if(a < b)
    {
        return b;
    }
    return a;
}

long get_usecs (void)
{
    struct timeval t;
    gettimeofday(&t,NULL);
    return t.tv_sec*1000000+t.tv_usec;
}

int main( int argc, char** argv ) {
    int ROW = 20;
    int COL = 20;



    float alpha =0.0;

    if(argc > 3)
    {
        ROW = atoi(argv[2]);
        COL = atoi(argv[3]);
        alpha = (float)atoi(argv[1])/10.0;
    }
    else if(argc > 2)
    {
        ROW = atoi(argv[2]);
        COL = atoi(argv[2]);
        alpha = (float)atoi(argv[1])/10.0;
    }
    else if(argc > 1)
    {
        alpha = (float)atoi(argv[1])/10.0;
    }
    printf("alpha: %f\n",alpha);
    float* AMAT = NULL;
    float* BMAT = NULL;

    float* CMATGPU = NULL;
    try{
        AMAT = new float[ROW*COL];
        BMAT = new float[ROW*COL];
        CMATCPU = new float[ROW*COL];
        CMATGPU = new float[ROW*COL];
        // initialize the matrices
        std::fill(AMAT, AMAT + ROW*COL, 1);
        std::fill(BMAT, BMAT + ROW*COL, 1);
        cotton::init_runtime();
        cotton::start_finish();

//
        cotton::async([=]() {
    //        std::cout<<"BeforeIN GPU async"<<std::endl<<COL<<" COL "<< ROW<<" ROW";
            gpukernel(AMAT, BMAT, CMATGPU, ROW, COL, alpha);


        });
      //  std::cout<<"Before CPU async"<<std::endl<<COL<<" COL "<< ROW<<" ROW";
       // cotton::async([=]() {

     // std::cout<<"BeforeIN CPU async"<<std::endl<<COL<<" COL "<< ROW<<" ROW";

       // });
        long start = get_usecs();
        cpukernel(AMAT, BMAT, CMATCPU, ROW, COL, alpha);

        cotton::end_finish();

        long end = get_usecs();
        float dur = ((double)(end-start))/1000000;
        printf("CPU TIME(%f) Time = %f Sec\n",alpha,dur);


        // Verify the result
        bool result=true;
        for (int i=0; i<ROW*COL; i++) {

            if (i / COL < (int)(alpha * ROW ) ) {
         //       printf(" G [%f] ",CMATGPU[i]);
                if(CMATGPU[i] != ROW)
                 result = false;
                //break;

            }
            if (i / COL > (int)(alpha * ROW) ) {
           //     printf(" C : [%f] ", CMATCPU[i]);
         if (CMATCPU[i] != ROW)
                    result = false;
            }
           /* if(i % ROW == 0)
                {
                    printf("\n");
                }
                */
        }
        std::cout<<"\n";
        for(int i = 0; i < ROW*COL;i++)
        {
            std::cout<<" "<<CMATCPU[i];
        }
        std::cout<<"\n";
        for(int i = 0; i < ROW*COL;i++)
        {
            std::cout<<" "<<CMATGPU[i];
        }
        if (result)
            std::cout<< "Success!\n";
        else
            std::cout<< "Failed!\n";

    }
    catch(cl::Error err) {
        std::cout << "Error: " << err.what() << "(" << err.err() << ")" << std::endl;
//        return( EXIT_FAILURE );


    }
  //  mydelete(AMAT);
  //  mydelete(BMAT);
  //  mydelete(CMATCPU);
  //  mydelete(CMATGPU);
    std::cout << "Done.\n";
    cotton::finalize_runtime();
    return( EXIT_SUCCESS );
}