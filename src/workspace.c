#include "headers/workspace.h"


vecEu calculateVector(point3pos p_ori,point3pos p_ext){

    vecEu resVec;

    resVec.u_vec = p_ext.x_coord - p_ori.x_coord;
    resVec.v_vec = p_ext.y_coord - p_ori.y_coord;
    resVec.w_vec = p_ext.z_coord - p_ori.z_coord;
    
    return resVec;
}