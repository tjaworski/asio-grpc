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

#ifndef AGRPC_DETAIL_MEMORY_RESOURCE_HPP
#define AGRPC_DETAIL_MEMORY_RESOURCE_HPP

#include <agrpc/detail/config.hpp>
#include <agrpc/detail/memory_resource_allocator.hpp>

#include <memory_resource>

AGRPC_NAMESPACE_BEGIN()

namespace detail
{
namespace pmr = std::pmr;
namespace container = std;

using GrpcContextLocalMemoryResource = detail::pmr::unsynchronized_pool_resource;
using GrpcContextLocalAllocator = detail::MemoryResourceAllocator<std::byte, detail::GrpcContextLocalMemoryResource>;

inline auto create_local_allocator(detail::GrpcContextLocalMemoryResource& resource) noexcept
{
    return detail::GrpcContextLocalAllocator{&resource};
}

inline auto new_delete_resource() noexcept { return detail::pmr::new_delete_resource(); }
}

AGRPC_NAMESPACE_END

#endif  // AGRPC_DETAIL_MEMORY_RESOURCE_HPP