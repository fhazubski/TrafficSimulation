#pragma once
#include "include/types.h"
#include "tslib_export.h"

void TSLIB_EXPORT foo();

TSP::tsp_id TSLIB_EXPORT tspAddVehicle(
    TSP::tsp_float x, TSP::tsp_float y, TSP::tsp_float width,
    TSP::tsp_float height, TSP::tsp_float frontAxle, TSP::tsp_float rearAxle,
    TSP::tsp_float rotation, TSP::tsp_float velocity);

bool TSLIB_EXPORT tspSetTime(TSP::tsp_float time);

TSP::tsp_vehicle_position TSLIB_EXPORT *tspGetPositions();
