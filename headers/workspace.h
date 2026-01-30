#ifndef WORKSPACE_H_
#define WORKSPACE_H_

typedef struct point3Position{
    uint32_t x_coord;
    uint32_t y_coord;
    uint32_t z_coord;
}point3pos;

typedef struct vectorEuclidean{
    uint32_t u_vec;
    uint32_t v_vec;
    uint32_t w_vec;
} vecEu;

vecEu calculateVector(point3pos p_ori,point3pos p_ext);

#endif