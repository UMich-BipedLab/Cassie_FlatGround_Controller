function generateUdpUserCode(outdir)
  %GENERATEUDPUSERCODE Generates C code needed by user computer UDP example
  %
  % Run this function to create the C headers and implementation files needed to
  % compile the udpuser example program.

  % Copyright 2018 Agility Robotics
   
  % Generate C files for CassieSlrtDataBus and CassieLinuxDataBus
  CodegenModule.generatePackingCode(...
    getSlrtDataStruct('annotated'), outdir, 'singlefloats');
  CodegenModule.generatePackingCode(...
    getLinuxDataStruct('annotated'), outdir, 'singlefloats');

end % generateUdpUserCCode
