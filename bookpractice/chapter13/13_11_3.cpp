#include "13_11_3.h"
#include <cstring>
// Abstract Base Class DMA methods
DMA::DMA(char const * l, int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

DMA::DMA(const DMA & dma)
{
    // delete [] label; 复制构造函数，指针还没分配内存地址
    label = new char[std::strlen(dma.label) + 1];
    std::strcpy(label, dma.label);
    rating = dma.rating;
}

DMA & DMA::operator=(const DMA & dma)
{
    if (this == & dma) // 地址相等  
        return * this;
    delete [] label;
    label = new char[std::strlen(dma.label) + 1];
    std::strcpy(label, dma.label);
    rating = dma.rating;
    return * this;
}

std::ostream & operator<<(std::ostream & os, const DMA & dma)
{
    os << "Label: " << dma.label << std::endl;
    os << "Rating: " << dma.rating << std::endl;
    return os;
}

// baseDMA methods
std::ostream & operator<<(std::ostream & os, const baseDMA & bdma)
{
    os << (const DMA & ) bdma; 
    return os;
}

void baseDMA::View() const
{
    std::cout << "label: " << Label();
    std::cout << "rating: " << Rating();
    std::cout << std::endl;
}

// lacksDMA methods
lacksDMA::lacksDMA(char const * c, char const * l, int r): DMA(l, r)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(char const * c, const DMA & dma): DMA(dma)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ldma)
{
    os << ldma.color << (const DMA & ) ldma;
    return os;
}

void lacksDMA::View() const
{
    std::cout << "color: " << color;
    std::cout << "label: " << Label();
    std::cout << "rating: " << Rating();
    std::cout << std::endl;
}

// hasDMA methods
hasDMA::hasDMA(char const * s, char const * l, int r): DMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(char const * s, const DMA & dma): DMA(dma)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs): DMA(hs) // 调用抽象基类的复制构造函数
{
    // delete [] style; 复制构造函数中的指针还没分配内存地址
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == & hs)
        return * this;
    delete [] style;
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    DMA::operator=(hs);
    return * this;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    os << hs.style << (const DMA & ) hs;
    return os;
}

void hasDMA::View() const
{
    std::cout << "style: " << style;
    std::cout << "label: " << Label();
    std::cout << "rating: " << Rating();
    std::cout << std::endl;
}