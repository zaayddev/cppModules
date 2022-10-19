#include "Fixed.hpp"
#include "Point.hpp"

Fixed *get_w1(Point const a, Point const b, Point const c, Point const p) {
    Fixed Ax = a.getX();
    Fixed Ay = a.getY();
    Fixed Bx = b.getX();
    Fixed By = b.getY();
    Fixed Cx = c.getX();
    Fixed Cy = c.getY();
    Fixed Px = p.getX();
    Fixed Py = p.getY();

    Fixed numerator = (Ax * (Cy - Ay)) + (Py - Ay) * (Cx - Ax) - Px * (Cy - Ay);
    Fixed denominator = (By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay);
    Fixed *w1 = new Fixed(numerator / denominator);

    return (w1);
}

Fixed *get_w2(Fixed w1, Point const a, Point const b, Point const c, Point const p) {
    Fixed Ay = a.getY();
    Fixed By = b.getY();
    Fixed Cy = c.getY();
    Fixed Py = p.getY();

    Fixed numerator = Py - Ay - w1 * (By - Ay);
    Fixed denominator = Cy - Ay;
    Fixed result = numerator / denominator;
    Fixed *w2 = new Fixed(result);

    return (w2);
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {
    Fixed *w1 = get_w1(a, b, c, p);
    Fixed *w2 = get_w2(*w1, a, b, c, p);

    bool ret = true;

    if (*w1 > 0 && *w2 > 0 && (*w1 + *w2) < 1)
        ret = true;
    else
        ret = false;
    delete w1;
    delete w2;
    
    return (ret);
}