#include "table.hpp"

Table::Table (const Table &table)
{
  this->width = table.getWidth ();
  this->height = table.getHeight ();
}

Table::Table (const int width, const int height)
    : width (width), height (height)
{
}

Table::~Table () {}

void
Table::operator= (const Table &table)
{
}

int
Table::getWidth () const
{
  return this->width;
}

int
Table::getHeight () const
{
  return this->height;
}

void
Table::setWidth (const int width)
{
  this->width = width;
}

void
Table::setHeight (const int height)
{
  this->height = height;
}
