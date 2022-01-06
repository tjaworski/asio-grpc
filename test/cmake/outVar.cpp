// Copyright 2022 Dennis Hezel
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "protos/outVar.grpc.pb.h"

#include <agrpc/asioGrpc.hpp>
#include <grpcpp/completion_queue.h>

void run_out_var()
{
    agrpc::GrpcContext grpc_context{std::make_unique<grpc::CompletionQueue>()};

    out_var::Request request;
    request.set_integer(42);

    out_var::Request response;

    grpc_context.run();
}