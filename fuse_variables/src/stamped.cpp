/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2018, Locus Robotics
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */
#include <string>

#include <fuse_core/node_interfaces/node_interfaces.hpp>
#include <fuse_core/parameter.hpp>
#include <fuse_core/uuid.hpp>
#include <fuse_variables/stamped.hpp>

namespace fuse_variables
{

fuse_core::UUID loadDeviceId(
  fuse_core::node_interfaces::NodeInterfaces<fuse_core::node_interfaces::Parameters> interfaces, const std::string& ns)
{
  std::string device_str;

  device_str = fuse_core::getParam(interfaces, fuse_core::joinParameterName(ns, "device_id"), std::string());
  if (!device_str.empty()) {
    return fuse_core::uuid::from_string(device_str);
  }

  device_str = fuse_core::getParam(interfaces, fuse_core::joinParameterName(ns, "device_name"), std::string());
  if (!device_str.empty()) {
    return fuse_core::uuid::generate(device_str);
  }

  std::cout << "\033[91m"
          << "[ERROR] loadDeviceId can not create a device_id. Wrongly set to fuse_core::uuid::NIL. Is namespace correctly configured?"
          << "\033[0m\n";

  return fuse_core::uuid::NIL;
}

}  // namespace fuse_variables
