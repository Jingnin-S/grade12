import numpy as np
a = np.array([2,3,4,5])
b = np.array([1,2,3,4])
print(a)
print("去")
tuple = ( 'runoob', 786 , 2.23, 'john', 70.2 )
tinytuple = (123, 'john')
 
print (tuple)               # 输出完整元组
print (tuple[0])            # 输出元组的第一个元素
print (tuple[1:3])          # 输出第二个至第四个（不包含）的元素 
print (tuple[2:])           # 输出从第三个开始至列表末尾的所有元素
print (tinytuple * 2)       # 输出元组两次
print (tuple + tinytuple)  
 
a = 21
b = 10
c = 0
 
if  a == b :
   print ("1 - a 等于 b")
else:
   print ("1 - a 不等于 b")