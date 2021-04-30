# Create a project
open_project -reset proj_matrix_multiply

# Add design files
add_files matrix_multiply.cpp
# Add test bench & files
add_files -tb matrix_multiply_test.cpp
#add_files -tb result.golden.dat

# Set the top-level function
set_top matrix_multiply

# ########################################################
# Create a solution
open_solution -reset solution1
# Define technology and clock rate
set_part  {xcvu9p-flga2104-2-i}
create_clock -period 4

# Source x_hls.tcl to determine which steps to execute
#source x_hls.tcl

set hls_exec 1

csim_design
# Set any optimization directives
# End of directives

if {$hls_exec == 1} {
	# Run Synthesis and Exit
	csynth_design

} elseif {$hls_exec == 2} {
	# Run Synthesis, RTL Simulation and Exit
	csynth_design

	cosim_design
} elseif {$hls_exec == 3} {
	# Run Synthesis, RTL Simulation, RTL implementation and Exit
	csynth_design

	cosim_design
	export_design
} else {
	# Default is to exit after setup
	csynth_design
}

exit

