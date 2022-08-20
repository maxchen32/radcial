# radical

不适合用于生产（代码质量感人）  
Not suitable for production use.

## 介绍

*分数、二次根式和多项式类*

C语言编写的基础分数、二次根式和多项式类库，支持増查删改。  
Elemental Fractions, Radicals and Polynomials.

本库通过GPLv3协议开源

## Compile

```bash
mkdir build
cd build 
cmake ..
```

The target `libradical.a` will be in the `build` directory.

## Usage

### fraction.h
```C
//数学
int       gcd(int a, int b);						//最大公因数
long long lgcd(long long a, long long b);
int       lcm(int a, int b);						//最小公倍数
int       qpow(int base, int expt);				//快速幂

//工具
Fraction initFrac(int up ,int down);       //初始化
void     fixsignFrac(Fraction* a);				//符号修正、错误处理
void     reduceFrac(Fraction* a);				//分数约分
void     reduce(int* a, int* b);              //数约分
void     printFrac(Fraction a);    //打印
int      _len_abs(int n);
void     pprintFrac(Fraction a);   //（实验性的）美观打印
int      cmpFrac(Fraction a, Fraction b);       //比较 返回-1 , 0 , 1
Fraction c(char myope, ...);               //运算器

//运算
Fraction addFrac(Fraction a, Fraction b);	//加法
Fraction subFrac(Fraction a, Fraction b);	//减法
Fraction mulFrac(Fraction a, Fraction b);	//乘法
Fraction divFrac(Fraction a, Fraction b);	//除法
Fraction powFrac(Fraction a, int expt);	//乘方
```

### radical.h
```C
//tool
Radical initRad(int up, int down, int in);
void printRad(Radical a);
Radical Radsqrt( int radicand );
Radical  sqrtFrac(Fraction a);               //分数开方
void printPoly(Polynomial ptrl);
int cmpRad(Radical a, Radical b);
bool isequalRad(Radical a, Radical b);

//calculation
Radical divRad(Radical a, Radical b);
Radical mulRad(Radical a, Radical b);
Polynomial addRad(Polynomial ptrl, Radical b);
Polynomial subRad(Polynomial ptrl, Radical b);
int gcdPoly(Polynomial ptrl);
Polynomial _PolyIntReduce(Polynomial ptrl, int* x);

//list
Polynomial initPoly();
void destoryPoly(Polynomial* ptrl);
int lenPoly(Polynomial ptrl);
Polynomial findPoly(Radical x, Polynomial ptrl);
Polynomial findkthPoly(int k, Polynomial ptrl);
Polynomial insertPoly(Radical x,int i, Polynomial ptrl );
Polynomial deletePoly(int i, Polynomial ptrl);
```

<del>作者还在代码里画了一些香喷喷的大饼</del>（头文件里没有）
