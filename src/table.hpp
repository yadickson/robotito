#pragma once

class Table
{
private:
  int width;
  int height;

public:
  explicit Table (const Table &table);
  explicit Table (const int width, const int height);
  virtual ~Table ();
  void operator= (const Table &table);
  virtual int getWidth () const;
  virtual int getHeight () const;
  virtual void setWidth (const int width);
  virtual void setHeight (const int height);
};
