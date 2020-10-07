#pragma once
#include "base/base.h"

#include "iterator.h"

//start models=============================================================================================================================
#include "models/array.h"
#include "models/set.h"
//end models-------------------------------------------------------------------------------------------------------------------------------
#include "data_base.h"
#include "base/view_helper.h"
//start views==============================================================================================================================
#include "views/home/index.h"
#include "views/int_array/index.h"
#include "views/int_array/show.h"
#include "views/int_set/index.h"
#include "views/int_set/show.h"
//end views--------------------------------------------------------------------------------------------------------------------------------
#include "base/controller_helper.h"
//start controllers========================================================================================================================

#include "controllers/home_controller.h"
#include "controllers/int_array_controller.h"
#include "controllers/int_set_controller.h"
//end controllers--------------------------------------------------------------------------------------------------------------------------
#include "base/rout.h"