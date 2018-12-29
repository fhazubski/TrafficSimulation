#pragma once
#include "tslib/types.h"
#include "tslib_export.h"

TSP::tsp_vehicle TSLIB_EXPORT *tspReserveVehicleMemory(TSP::tsp_int vehiclesCount);

TSP::tsp_obstacle_line TSLIB_EXPORT *
tspReserveObstacleMemory(TSP::tsp_int obstaclesCount);

bool TSLIB_EXPORT tspAddVehicle(TSP::tsp_float x, TSP::tsp_float y,
                                TSP::tsp_float width, TSP::tsp_float height,
                                TSP::tsp_float axleDistance,
                                TSP::tsp_float frontWheelsDistance,
                                TSP::tsp_float rotation,
                                TSP::tsp_float velocity);

void TSLIB_EXPORT tspOverrideAxleAngle(TSP::tsp_id vehicle, TSP::tsp_float angle);

bool TSLIB_EXPORT tspSetTime(TSP::tsp_float time);

TSP::tsp_vehicle_position TSLIB_EXPORT *tspGetPositions();
