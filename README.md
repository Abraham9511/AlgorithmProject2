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
