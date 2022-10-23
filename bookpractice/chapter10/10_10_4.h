// class definition for the Sales
#ifndef SALES_H_
#define SALES_H_
namespace  SALES
{
    class Sales
    {
        private:
            static const int QUARTERS = 4; // 同一个类的所有对象共享，全局变量
            double sales[QUARTERS];
            double average;
            double max;
            double min;
        public:
            Sales();
            Sales(const double ar[], int n);
            void setSales();
            void show() const;
    };
} // namespace  SALES

#endif