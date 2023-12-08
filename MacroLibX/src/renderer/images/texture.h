/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:24:58 by maldavid          #+#    #+#             */
/*   Updated: 2023/11/25 10:01:35 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MLX_TEXTURE__
#define __MLX_TEXTURE__

#include <filesystem>
#include <memory>
#include <array>
#include <functional>
#include <renderer/images/vk_image.h>
#include <renderer/descriptors/vk_descriptor_set.h>
#include <renderer/buffers/vk_ibo.h>
#include <renderer/buffers/vk_vbo.h>

namespace mlx
{
	class Texture : public Image
	{
		public:
			Texture() = default;
			
			void create(uint8_t* pixels, uint32_t width, uint32_t height, VkFormat format, const char* name, bool dedicated_memory = false);
			void render(class Renderer& renderer, int x, int y);
			void destroy() noexcept override;

			void setPixel(int x, int y, uint32_t color) noexcept;
			int getPixel(int x, int y) noexcept;

			inline void setDescriptor(DescriptorSet set) noexcept { _set = std::move(set); }
			inline VkDescriptorSet getSet() noexcept { return _set.isInit() ? _set.get() : VK_NULL_HANDLE; }
			inline void updateSet(int binding) noexcept { _set.writeDescriptor(binding, getImageView(), getSampler()); _has_been_updated = true; }
			inline bool hasBeenUpdated() const noexcept { return _has_been_updated; }
			inline constexpr void resetUpdate() noexcept { _has_been_updated = false; }

			~Texture() = default;

		private:
			void openCPUmap();

		private:
			C_VBO _vbo;
			C_IBO _ibo;
			#ifdef DEBUG
				std::string _name;
			#endif
			DescriptorSet _set;
			std::vector<uint32_t> _cpu_map;
			std::optional<Buffer> _buf_map = std::nullopt;
			void* _map = nullptr;
			bool _has_been_modified = false;
			bool _has_been_updated = false;
	};

	Texture stbTextureLoad(std::filesystem::path file, int* w, int* h);

	struct TextureRenderData
	{
		Texture* texture;
		std::size_t hash = 0;
		int x;
		int y;

		TextureRenderData(Texture* _texture, int _x, int _y) : texture(_texture), x(_x), y(_y) {}
		bool operator==(const TextureRenderData& rhs) const { return texture == rhs.texture && x == rhs.x && y == rhs.y; }
	};
}

namespace std
{
	template <>
	struct hash<mlx::TextureRenderData>
	{
		size_t operator()(const mlx::TextureRenderData& td) const noexcept
		{
			return std::hash<mlx::Texture*>()(td.texture) + std::hash<int>()(td.x) + std::hash<int>()(td.y);
		}
	};
}

#endif
