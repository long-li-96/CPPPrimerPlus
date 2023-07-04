/*
1、使用成员函数位Stonewt类重载乘法运算符，该运算符将数据成员与double类型的值相乘。注意，用英石和磅表示
时，需要进位，也就是说，将10英石8磅乘以2等于21英石2磅
// prototype
Stonewt operator * (double mult);
// definition-let constructor do the work
Stonewt Stonewt::operator*(double mult)
{
    return Stonewt(mult * pounds);
}

2、友元函数与成员函数之间的区别是什么？
成员函数是类定义的一部份，通过特定的对象来调用。成员函数可以隐式访问调用对象的成员，无需使用成员运算符。
友元函数不是类的组成部份，因此被称为直接函数调用。友元函数不能隐式访问成员，而必须将成员运算符用于作为参数
传递的对象。比较1和4

3、非成员函数必须是友元才能访问类成员吗？
要访问私有成员，它必须是友元，但要访问公有成员，可以不是友元

4、使用友元函数为Stonewt类重载乘法运算符，该运算符将double值与Stone值相乘
// protype
friend Stonewt operator*(double mult, const Stonewt & s);
// definition-let constructor do the work
Stonewt operator * (double mult, const Stonewt & s)
{
    return Stonewt(mult * s.pounds);
}

5、哪些运算符不能重载？
sizeof . .* :: ?:

6、在重载运算符=、()、[]和->时，有什么限制？
这些运算符必须使用成员函数来定义。

7、为Vector类定义一个转换函数，将Vector类转换为一个double类型的值，后者表示矢量的长度
// prototype and inline definition
operator double () {return mag;}


*/