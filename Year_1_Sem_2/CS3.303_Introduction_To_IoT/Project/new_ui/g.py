import matplotlib.pyplot as plt

x=[1,2,3,4,5,6,7]
y=[1,4,5,2,0,5,8]
plt.figure(facecolor='black')
plt.xlabel('Timestamps',color='white')
plt.ylabel('Pressure',color='white',labelpad=30)
ax = plt.axes()
ax.spines['bottom'].set_color('white')
ax.spines['left'].set_color('white')
# ax.yaxis.set_label_coords(-10, 0.5)
# ax.yaxis.labelpad = 50 
ax.set_facecolor("(0, 0, 0, 0.6)")
plt.plot(x,y,color='orange',marker="o")
# plt.subplots_adjust(left=0.20, bottom=0.15, right=0.9, top=0.9)
plt.tick_params(axis='x', colors='white')
plt.tick_params(axis='y', colors='white')




plt.show()