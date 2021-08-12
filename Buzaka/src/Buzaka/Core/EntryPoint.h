#pragma once

#ifdef BZ_PLATFORM_WINDOWS

#include "Log.h"
#include "Application.h"

int main( int argc, char** argv )
{
  Buzaka::Log::Init();
  BZ_CORE_INFO( "Log is initialized." );
  auto app = Buzaka::CreateApplication();
  BZ_CORE_INFO( "An application is running" );
  app->Run();
  delete app;
}

#endif // BZ_PLATFORM_WINDOWS
