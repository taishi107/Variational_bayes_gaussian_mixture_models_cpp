import numpy as np
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA

#with open('training1.csv') as f:
    #print(f.read())

maze = np.loadtxt('training1.csv', delimiter=',' ,skiprows=1)
az = np.transpose(maze)[0][0::2]
lx = np.transpose(maze)[1][0::2]
lf = np.transpose(maze)[2][0::2]
rf = np.transpose(maze)[3][0::2]
ls = np.transpose(maze)[4][0::2]
rs = np.transpose(maze)[5][0::2]

sensor_values = np.c_[lf,ls,rf,rs]

ss = StandardScaler().fit(sensor_values)
normalize_data = ss.transform(sensor_values)

pca = PCA(n_components=2).fit(normalize_data)
data = pca.transform(normalize_data)
print(data)

np.savetxt("sensor_data.csv",data,delimiter=",")
