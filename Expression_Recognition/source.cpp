// Copyright (C) 2006  Davis E. King (davis@dlib.net)
// License: Boost Software License   See LICENSE.txt for the full license.

#ifndef DLIB_ALL_SOURCe_
#define DLIB_ALL_SOURCe_

#if defined(DLIB_ALGs_) || defined(DLIB_PLATFORm_)
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib/dlib_basic_cpp_build_tutorial.txt"
#endif
//#include "stdafx.h"
// ISO C++ code
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\base64\base64_kernel_1.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\bigint\bigint_kernel_1.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\bigint\bigint_kernel_2.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\bit_stream\bit_stream_kernel_1.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\entropy_decoder\entropy_decoder_kernel_1.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\entropy_decoder\entropy_decoder_kernel_2.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\entropy_encoder\entropy_encoder_kernel_1.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\entropy_encoder\entropy_encoder_kernel_2.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\md5\md5_kernel_1.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\tokenizer\tokenizer_kernel_1.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\unicode\unicode.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\test_for_odr_violations.cpp"




#ifndef DLIB_ISO_CPP_ONLY
// Code that depends on OS specific APIs

// include this first so that it can disable the older version
// of the winsock API when compiled in windows.
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\sockets\sockets_kernel_1.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\bsp\bsp.cpp"

#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\dir_nav\dir_nav_kernel_1.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\dir_nav\dir_nav_kernel_2.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\dir_nav\dir_nav_extensions.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\linker\linker_kernel_1.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\logger\extra_logger_headers.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\logger\logger_kernel_1.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\logger\logger_config_file.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\misc_api\misc_api_kernel_1.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\misc_api\misc_api_kernel_2.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\sockets\sockets_extensions.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\sockets\sockets_kernel_2.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\sockstreambuf\sockstreambuf.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\sockstreambuf\sockstreambuf_unbuffered.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\server\server_kernel.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\server\server_iostream.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\server\server_http.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\threads\multithreaded_object_extension.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\threads\threaded_object_extension.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\threads\threads_kernel_1.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\threads\threads_kernel_2.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\threads\threads_kernel_shared.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\threads\thread_pool_extension.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\threads\async.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\timer\timer.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\stack_trace.cpp"

#ifdef DLIB_PNG_SUPPORT
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\image_loader\png_loader.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\image_saver\save_png.cpp"
#endif

#ifdef DLIB_JPEG_SUPPORT
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\image_loader\jpeg_loader.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\image_saver\save_jpeg.cpp"
#endif

#ifndef DLIB_NO_GUI_SUPPORT
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\gui_widgets\fonts.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\gui_widgets\widgets.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\gui_widgets\drawable.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\gui_widgets\canvas_drawing.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\gui_widgets\style.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\gui_widgets\base_widgets.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\gui_core\gui_core_kernel_1.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\gui_core\gui_core_kernel_2.cpp"
#endif // DLIB_NO_GUI_SUPPORT

#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\cuda\cpu_dlib.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\cuda\tensor_tools.cpp"

#endif // DLIB_ISO_CPP_ONLY



#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\data_io\image_dataset_metadata.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\data_io\mnist.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\global_optimization\global_function_search.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\filtering\kalman_filter.cpp"
#include "D:\programfiles\dlib-19.14\dlib-19.14\dlib\svm\auto.cpp"


#define DLIB_ALL_SOURCE_END

#endif // DLIB_ALL_SOURCe_

