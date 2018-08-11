#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <vector>
using namespace std;

class CVector {
public:
    CVector() :	_x(0), _y(0) {}
    CVector(double x, double y) : _x(x), _y(y) {}
    CVector(const CVector& v) :	_x(v.x()), _y(v.y()) {}
    double mod() const { return sqrt(_x * _x + _y * _y); }
    double dir() const { return atan2(_y, _x);}
    CVector rotate(double angle) const;
    double x() const { return _x; }
    double y() const { return _y; }
    CVector operator +(const CVector& v) const { return CVector(_x + v.x(), _y + v.y()); }
    CVector operator -(const CVector& v) const { return CVector(_x - v.x(), _y - v.y()); }
    CVector operator *(double a) const { return CVector(_x * a, _y * a); }
    double operator *(CVector b) const { return double(_x * b.x() + _y * b.y()); } //向量点乘
    CVector operator /(double a) const { return CVector(_x / a, _y / a); }
    CVector operator -() const { return CVector(-1 * _x, -1 * _y); }
private:
    double _x, _y;
};

class CGeoPoint {
public:
    CGeoPoint() : _x(0), _y(0) {}
    CGeoPoint(double x, double y) : _x(x), _y(y) {}
    CGeoPoint(const CGeoPoint& p) : _x(p.x()), _y(p.y()) {}
    bool operator ==(const CGeoPoint& rhs) { return ((this->x() == rhs.x()) && (this->y() == rhs.y())); }
    double x() const { return _x; }
    double y() const { return _y; }
    double dist(const CGeoPoint& p) const { return CVector(p - CGeoPoint(_x, _y)).mod(); }
    CGeoPoint operator +(const CVector& v) const { return CGeoPoint(_x + v.x(), _y + v.y()); }
    CGeoPoint operator *(const double& a) const { return CGeoPoint(_x * a, _y * a); }
    CVector operator -(const CGeoPoint& p) const { return CVector(_x - p.x(), _y - p.y()); }
    CGeoPoint midPoint(const CGeoPoint& p) const{ return CGeoPoint((_x + p.x()) / 2, (_y + p.y()) / 2); }
private:
    double _x, _y;
};

struct MoveObj {
public:
    MoveObj() {}
    CGeoPoint pos() const { return _pos; }
    CVector vel() const { return _vel; }
    void setPos(const CGeoPoint& pos) { _pos = CGeoPoint(pos); }
    void setVel(const CVector& vel) { _vel = CVector(vel); }
    CGeoPoint _pos;
    CVector _vel;
};

typedef MoveObj Obstacle;

class Robot : public MoveObj {
public:
    Robot() {}
    CGeoPoint pos() const { return _pos; }
    CVector vel() const { return _vel; }
    double dir() const { return _dir; }
    double rotVel() const { return _rotVel; }
    void setPos(const CGeoPoint& pos) { _pos = CGeoPoint(pos); }
    void setVel(const CVector& vel) { _vel = CVector(vel); }
    void setDir(const double& dir) { _dir = dir; }
    void setRotVel(const double& rotVel) { _rotVel = rotVel; }
private:
    double _dir;
    double _rotVel;
};

class RoundObstacle : private Obstacle {

};

class RectObstacle : private Obstacle {

};

#endif // MODEL_H
