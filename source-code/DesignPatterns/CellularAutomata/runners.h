#ifndef RUNNERS_HDR
#define RUNNERS_HDR

#include <variant>

#include "cells.h"
#include "cycle_finder.h"
#include "dynamics.h"
#include "visualization_runner.h"

using RunnerVariant = std::variant<CycleFinder, VisualizationRunner>;
void execute_runner(RunnerVariant& runner, Dynamics& dynamics, Cells& cells);

#endif
