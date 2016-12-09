# AlgorithmProject2
算法作业第二个Project

### 作业要求
![](./pic/requirements.png)

Algorithm 1 是概述整体的流程
Algorithm 2 是随机投影的实现
Algorithm 3 和 4是排序以及需找最近对的方法， 3 是合并排序 4是快排

### 分工 ？
* Algotirhm2&3实现（算法的实现按照函数的形式） 
* Algorithm2&4实现
* 读取数据，存储数据，显示数据（简单实现了三个功能，用类包装，可以直接调用），这里可以实现主程序
* 枚举法求解
* 文档（应该可以分配给写算法的人进行running time的分析）

### 提交
![](./pic/submission.png)

### 难点
~~  这个算法要实现最优化的参数设置，找多几组数据测试，然后暴力找到最优化解以及次优，第三优，等等，看看算法实现出来的结果怎么样。m该怎么取 ~~
实际上维度是确定的

### 算法截图
![](./pic/Algorithm1.png)
![](./pic/Algorithm2.png)
![](./pic/Algorithm3.png)
![](./pic/Algorithm4.png)


### 编译
> g++ -std=c++11 cp.cpp algorithm1.cpp algorithm2.cpp algorithm3.cpp algorithm4.cpp Enumeration.cpp Image.cpp -o cp

### 运行
在src下
> ./cp -n 60000 -d 784 -f train-images.idx3-ubyte

### 进程
#### 11.27
* A1, A2, A3, A4 Enumeration可以跑
* 效果比较差
* makefile不能启动，只能 
g++ -std=c++11 cp.cpp algorithm1.cpp algorithm2.cpp algorithm3.cpp algorithm4.cpp Enumeration.cpp Image.cpp -o cp
* 第一次输出结果查看first_test.log

#### 11.28 
* 第二次输出结果查看second_test.log
枚举出来的效果表明，我们的算法的效果很不行
* Enumeration函数为了返回多个pair，因而修改了返回的形式参数的模样为vector< pair<int,int> >

#### 12.2
显然，根据日志观察到两个算法花费的时间都是颇为巨大的
已经有小组能把时间限制到20s，而我们两个算法最快的也是其15倍，最慢的是20倍。
需要优化
包括映射，两个排序
以及每个部分都要编写相应的文档

#### 12.9 优化
主要是对cp.cpp和Algorithm1.cpp的修改  
增加了cp.h文件  
以及
还有makefile具备三个功能

```
make 
make clean
make run
```
* cp.cpp中形成将 大端转小端 写成一个新函数， 将文件转化为Image类写成一个函数
* Algorithm1.cpp将原本的两个函数（一个执行归并排序，一个执行快排序）合并为一个，共用相同的随机向量
* Algorithm1.cpp将所有文件中存储所有图像映射到所有随机向量上的向量机中在Closet_Pair函数中，只用声明初始化一次，减少内存以及声明的时间
* 最重要的修改莫过于按照proj的要求，将随机向量的数量从 **60000** 减少到 **100**，缩小了600，花费时间明显减少
* Algorithm3和Algorithm4的接口改变
* Image的打印的图像的样式反转了

### 代码组成
#### 文件目录
#### 具体文件的接口以及相应解释
##### Image 

### 贡献者
欧光文，庄嘉鑫，徐嘉辰，夏中舟

### 参考资料：
1. [LCG](http://blog.csdn.net/jackytintin/article/details/7798157)
2. [box-Muller](https://www.zhihu.com/question/29971598)
3. [h文件和cpp文件](http://www.cnblogs.com/ider/archive/2011/06/30/what_is_in_cpp_header_and_implementation_file.html)
4. [makefile](http://wiki.ubuntu.org.cn/%E8%B7%9F%E6%88%91%E4%B8%80%E8%B5%B7%E5%86%99Makefile:MakeFile%E4%BB%8B%E7%BB%8D)
5. [ubuntu简单写makefile](http://wiki.ubuntu.org.cn/%E8%B7%9F%E6%88%91%E4%B8%80%E8%B5%B7%E5%86%99Makefile:MakeFile%E4%BB%8B%E7%BB%8D)
6. [大端小端](http://blog.sina.com.cn/s/blog_9f1c0931010193ct.html)
7. [大端小端转换](http://www.blogjava.net/tinysun/archive/2009/12/31/307952.html)
8. [google注释书写规范](http://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/comments/)
