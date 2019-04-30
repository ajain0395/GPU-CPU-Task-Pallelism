import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

width = .35 # width of a bar

m1_t = pd.DataFrame({
 'Energy' : [329.02,258.29,205.81,191.81,168.83,151.99,128.39,112.09,96.23,105.67,107.32],
# 'fix' : [60,70,65,70,70,60,50,45,45,45],
# 'normal' : [140,160,170,180,190,200,210,220,230,240],
 'Execution Time' : [11.3,11.9,11.5,10.4,8.6,7.7,6.3,5.1,3.8,4.5,4.8]})
plt.legend(['Energy'])
m1_t[['Energy']].plot(kind='bar', width = width)
m1_t['Execution Time'].plot(secondary_y=True,c="red",linestyle="--")
plt.legend(['TIME'],loc=3)
ax = plt.gca()
# plt.xlim([-width, len(m1_t['Energy'])-width])
# plt.xlim([-width, len(m1_t['Execution Time'])-width])

ax.set_xticklabels(('0','10', '20', '30', '40', '50', '60', '70', '80', '90', '100'))
plt.title("Percentage of work assigned to GPU")

# plt.legend(["Execution Time"],loc='best')
plt.show()
plt.figure()
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

width = .35 # width of a bar

m1_t = pd.DataFrame({
 'CPU' : [329.02],
 'GPU' : [107.32],
 'PERF' : [112.09],
 'EAS' : [105]})

m1_t[['CPU','GPU','PERF',"EAS"]].plot(kind='bar', width = width)
# m1_t[['GPU']].plot(kind='bar', width = width)
# m1_t[['PERF']].plot(kind='bar', width = width)
# m1_t[['EAS']].plot(kind='bar', width = width)
# m1_t['EAS'].plot(secondary_y=True)
#m1_t['Execution Time'].plot(secondary_y=True,c="red",linestyle="--",label="23")

#ax = plt.gca()
# plt.xlim([-width, len(m1_t['Energy'])-width])
ax.set_xticklabels((["mm"]))

#plt.legend(['Energy',"Execution Time"])
plt.title("Energy")

plt.show()
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
plt.figure()
width = .35 # width of a bar

m1_t = pd.DataFrame({
 'CPU' : [329.02 * 11.3],
 'GPU' : [107.32 * 4.8],
 'PERF' : [112.09 * 5.1],
 'EAS' : [105 * 4.5]})

m1_t[['CPU','GPU','PERF',"EAS"]].plot(kind='bar', width = width)
# m1_t[['GPU']].plot(kind='bar', width = width)
# m1_t[['PERF']].plot(kind='bar', width = width)
# m1_t[['EAS']].plot(kind='bar', width = width)
# m1_t['EAS'].plot(secondary_y=True)
#m1_t['Execution Time'].plot(secondary_y=True,c="red",linestyle="--",label="23")

#ax = plt.gca()
# plt.xlim([-width, len(m1_t['Energy'])-width])
ax.set_xticklabels((["mm"]))

#plt.legend(['Energy',"Execution Time"])
plt.title("Energy Delay")
plt.show()
