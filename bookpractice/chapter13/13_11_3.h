#ifndef DMA1_H_
#define DMA1_H_
#include <iostream>

// Abstract Base Class
class DMA
{
private:
    char * label;
    int rating;

protected:
    char * Label() const {return label;}
    int Rating() const {return rating;}

public:
    DMA(char const * l = "null", int r = 0);
    DMA(const DMA & dma);
    virtual ~DMA() {delete [] label;}
    DMA & operator=(const DMA & dma);
    friend std::ostream & operator<<(std::ostream & os, const DMA & dma);
    virtual void View() const = 0; // 纯虚函数
};

class baseDMA: public DMA
{
public:
    baseDMA(char const * l = "null", int r = 0): DMA(l, r) {}
    baseDMA(const DMA & dma): DMA(dma) {} 
    // baseDMA(const baseDMA & bdma); 没有使用new动态内存分配，不需要显式定义
    // virtual ~baseDMA() {} 没有使用new动态内存分配，不需要显式定义
    // baseDMA & operator=(const baseDMA & bdma); 没有使用new动态内存分配，不需要显式定义
    friend std::ostream & operator<<(std::ostream & os, const baseDMA & bdma);
    virtual void View() const;
};

class lacksDMA: public DMA
{
private:
    enum { COL_LEN = 40};
    char color[COL_LEN];

public:
    lacksDMA(char const * c = "blank", char const * l = "null", int r = 0);
    lacksDMA(char const * c, const DMA & dma);
    // lacksDMA(const lacksDMA & ldma);
    // virtual ~lacksDMA() {} 没有new不需要显示定义
    // lacksDMA & operator=(const lacksDMA & ldma); 没有new不需要显示定义
    friend std::ostream & operator<<(std::ostream & os, const lacksDMA & ldma);
    virtual void View() const;
};

class hasDMA: public DMA
{
private:
    char * style;

public:
    hasDMA(char const * s = "none", char const * l = "null", int r = 0);
    hasDMA(char const * s, const DMA & dma);
    hasDMA(const hasDMA & hs);
    virtual ~hasDMA();
    hasDMA & operator=(const hasDMA & hs);
    friend std::ostream & operator<<(std::ostream & os, const hasDMA & hs);
    virtual void View() const;
};

#endif