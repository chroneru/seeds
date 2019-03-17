
#include <R.h>
#include "seeds_cycl.h"

double cycl_x_calc(double radius_c, double radius_m, double rad, int func_num) {
    double cycl_x = 0;

    switch(func_num) {
        /* epicycloid */
        case 1:
            cycl_x = (radius_c + radius_m) * cos(rad) -
                    radius_m * cos(
                        (radius_c + radius_m) / radius_m * rad
                        );
            break;

        /* hypocycloid */
        case 2:
            cycl_x = (radius_c - radius_m) * cos(rad) +
                    radius_m * cos(
                        (radius_c - radius_m) / radius_m * rad
                        );
            break;

        default:
            cycl_x = radius_m * (rad - sin(rad));
    }

    return cycl_x;
}

double cycl_y_calc(double radius_c, double radius_m, double rad, int func_num) {
    double cycl_y = 0;

    switch(func_num) {
        /* epicycloid */
        case 1:
            cycl_y = (radius_c + radius_m) * sin(rad) -
                    radius_m * sin(
                        (radius_c + radius_m) / radius_m * rad
                        );
            break;

        /* hypoycloid */
        case 2:
            cycl_y = (radius_c - radius_m) * sin(rad) -
                    radius_m * sin(
                        (radius_c - radius_m) / radius_m * rad
                        );
            break;

        default:
            cycl_y = radius_m * (1 - cos(rad));
    }

    return cycl_y;
}
