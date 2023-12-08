/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vk_descriptor_pool.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:32:43 by maldavid          #+#    #+#             */
/*   Updated: 2023/01/23 18:44:40 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VK_DESCRIPTOR_POOL__
#define __VK_DESCRIPTOR_POOL__

#include <volk.h>
#include <cstddef>

namespace mlx
{
	class DescriptorPool
	{
		public:
			void init(std::size_t n, VkDescriptorPoolSize* size);
			void destroy() noexcept;

			inline VkDescriptorPool& operator()() noexcept { return _pool; }
			inline VkDescriptorPool& get() noexcept { return _pool; }

		private:
			VkDescriptorPool _pool = VK_NULL_HANDLE;
	};
}

#endif
