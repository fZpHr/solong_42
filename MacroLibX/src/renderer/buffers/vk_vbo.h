/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vk_vbo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:27:38 by maldavid          #+#    #+#             */
/*   Updated: 2023/11/14 04:53:36 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MLX_VK_VBO__
#define __MLX_VK_VBO__

#include "vk_buffer.h"
#include <renderer/renderer.h>

namespace mlx
{
	class VBO : public Buffer
	{
		public:
			inline void create(uint32_t size, const char* name) { Buffer::create(Buffer::kind::dynamic, size, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, name); }
			void setData(uint32_t size, const void* data);
			inline void bind(Renderer& renderer) noexcept { vkCmdBindVertexBuffers(renderer.getActiveCmdBuffer().get(), 0, 1, &_buffer, &_offset); }
	};

	class C_VBO : public Buffer
	{
		public:
			inline void create(uint32_t size, const void* data, const char* name) { Buffer::create(Buffer::kind::constant, size, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, name, data); }
			inline void bind(Renderer& renderer) noexcept { vkCmdBindVertexBuffers(renderer.getActiveCmdBuffer().get(), 0, 1, &_buffer, &_offset); }
	};
}

#endif // __MLX_VK_VBO__
