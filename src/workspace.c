#include "headers/workspace.h"


vecEu calculateVectortwoPoints(point3pos p_ori,point3pos p_ext){

    vecEu resVec;

    resVec.u_vec = p_ext.x_coord - p_ori.x_coord;
    resVec.v_vec = p_ext.y_coord - p_ori.y_coord;
    resVec.w_vec = p_ext.z_coord - p_ori.z_coord;
    
    return resVec;
}

vecUT calculateUnitVector(vecEu posVec,vecUT unitVec){
    vecUT resUnit;
    resUnit.i_vec = posVec.u_vec * unitVec.i_vec + posVec.v_vec * unitVec.j_vec + posVec.w_vec * unitVec.k_vec; 
    return resUnit;
}