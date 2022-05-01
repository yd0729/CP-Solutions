### 一、模板类别

​	数据结构：李超线段树

### 二、模板功能

#### 1.建立线段树

1. 数据类型

   模板参数 `typename _Line` ，表示线段的类型，默认值为 `OY::LichaoLine` 。

   模板参数 `typename _Compare` ，表示比较函数的类，默认值为 `OY::LichaoLess<_line>` 。

   构造参数 `int n` ，表示线段树的覆盖范围为 `[0,n)​`。

   构造参数 `_Compare __comp` ，表示具体的比较函数，默认值为 `_Compare` 类的默认构造实例。

   构造参数 `_Line __line` ，表示元素默认值，默认为 `_Line` 类的默认实例。

2. 时间复杂度

   $O(n)$ 。

3. 备注

   李超线段树处理的问题为，给出多个一元一次函数，查询单点的函数最值。

   元素类型限定为**线段**，但是李超线段树可以解决大部分**直线**问题，只要把自变量定义域按照问题范围进行截取即可。

   李超线段树需要提供线段数据类型，以及比较函数。在一般情况下可以使用默认的类型 `OY::LichaoLine` 及默认比较类 `OY::LichaoLess<_line>` 。`OY::LichaoLine`由两个参数组成，`double k` 表示斜率，`double b` 表示截距；`OY::LichaoLess<_line>` 设计类似于 `std::less`，但是接受三个参数，参数一和参数二为`_Line`参数，参数三为横坐标 `x` ，当在这个横坐标处直线一低于直线二时返回 `true`，否则返回 `false` 。

   使用自定义的线段数据类型也是可以的，具体见范例。

#### 2.重置

1. 数据类型

   输入参数 `int __n` ，表示将李超线段树的覆盖范围重置为 `[0, n)`。

2. 时间复杂度

   $O(n)$ 。

3. 备注

   重置可以改变李超线段树的覆盖范围，并重置这个范围的值。

#### 3.添加线段

1. 数据类型

   输入参数 `int __left` ，表示线段的起始下标

   输入参数 `int __right` ，表示线段的结尾下标。（闭区间）

   输入参数 `_Line __line` ，表示要添加的线段。

2. 时间复杂度

   $O(\log^2 n)$ ，特别的，如果添加的线段全部为直线（也就是覆盖整个区间），时间复杂度为 $O(\log n)$ 。

3. 备注

   本函数的时间复杂度本质上取决于插入的线段区间会不会被分成很多个 `2` 的幂长度的小区间。比如，区间 `[256, 320)` 只会被分成一块长度为 `64` 的区间；区间 `[9, 15)` 会被分割成四块：`[9, 10), [10, 12), [12，14), [14, 15)` 。（为什么 `[10, 12)` 和 `[12, 14)` 不能合并？留待思考）完整易分的区间越多，时间复杂度越接近 $O(\log n)$ 。

#### 4.单点查询最优线段

1. 数据类型

   输入参数 $int\space i$ ，表示单点查询的下标。

2. 时间复杂度

   $O(\log n)$ 。

### 三、模板示例

```c++
#include "DS/LichaoTree.h"
#include "IO/FastIO.h"

int main() {
    //默认的李超线段树使用斜率和截距描述线段
    OY::LichaoTree T(16);
    T.add(8,10,{1.5,-7});
    T.add(2,6,{0.25,5.5});
    T.add(4,6,{0,7});

    cout<<"x=2, max(Y)="<<T.query(2).calc(2)<<endl;
    cout<<"x=4, max(Y)="<<T.query(4).calc(4)<<endl;
    // x=7 没有被添加的线段覆盖，所以返回的是默认值
    cout<<"x=7, max(Y)="<<T.query(7).calc(7)<<endl;
    cout<<"x=8, max(Y)="<<T.query(8).calc(8)<<endl;

    //*****************************************************************************
    //如果要添加自定义线段，需要给线段提供calc方法，才能使用 OY::LichaoLess 比较方法
    struct line{
        int k;
        int b;
        std::string name;
        int calc(int i)const{return k*i+b;}
    };
    OY::LichaoTree<line>T2(16);
    T2.add(8,10,{1,-7,"apple"});
    T2.add(8,10,{2,-10,"banana"});
    T2.add(8,10,{-1,10,"cat"});
    cout<<"x=9, highest line'name="<<T2.query(9).name<<endl;

    //*****************************************************************************
    //如果 OY::LichaoLess 也不能满足你的需求，那你可以自己写比较函数
    //比如这一次要求：首先选择函数值比较低的；在函数值并列的时候，选择名字字典序最小的线段
    struct compare{
        bool operator()(const line&x,const line&y,int i)const{
            int x_val=x.calc(i),y_val=y.calc(i);
            if(x_val!=y_val)return x_val>y_val;
            else return x.name>y.name;
        }
    };
    //注意，如果要比较的线段都位于 x 轴上方，那么默认线段需要设得高一些
    OY::LichaoTree T3(16,compare(),line{0,INT_MAX,"default"});
    T3.add(0,15,{1,0,"one"});
    T3.add(0,15,{0,4,"two"});
    T3.add(0,15,{-1,8,"three"});
    T3.add(0,15,{-2,12,"four"});
    cout<<"x=4, lowest line'name="<<T3.query(4).name<<endl;
}
```

```
#输出如下
x=2, max(Y)=6.000000
x=4, max(Y)=7.000000
x=7, max(Y)=0.000000
x=8, max(Y)=5.000000
x=9, highest line'name=banana
x=4, lowest line'name=four

```

