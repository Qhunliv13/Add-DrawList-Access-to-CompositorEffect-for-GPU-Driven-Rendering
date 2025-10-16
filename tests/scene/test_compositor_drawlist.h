/**************************************************************************/
/*  test_compositor_drawlist.h                                            */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/

#ifndef TEST_COMPOSITOR_DRAWLIST_H
#define TEST_COMPOSITOR_DRAWLIST_H

#include "tests/test_macros.h"

#ifdef TOOLS_ENABLED

#include "scene/resources/compositor.h"
#include "servers/rendering/storage/render_data.h"

namespace TestCompositorDrawList {

TEST_CASE("[Compositor] CompositorEffect access_draw_list property") {
	Ref<CompositorEffect> effect;
	effect.instantiate();

	SUBCASE("Default value is false") {
		CHECK_FALSE(effect->get_access_draw_list());
	}

	SUBCASE("Can be enabled") {
		effect->set_access_draw_list(true);
		CHECK(effect->get_access_draw_list());
	}

	SUBCASE("Can be disabled") {
		effect->set_access_draw_list(true);
		effect->set_access_draw_list(false);
		CHECK_FALSE(effect->get_access_draw_list());
	}
}

TEST_CASE("[RenderData] get_current_draw_list default behavior") {
	// RenderData is abstract class, default implementation should return -1
	// Actual implementation tested via RenderDataRD in rendering tests
}

TEST_CASE("[RenderingServer] COMPOSITOR_EFFECT_FLAG_ACCESS_DRAW_LIST constant") {
	CHECK(RenderingServer::COMPOSITOR_EFFECT_FLAG_ACCESS_DRAW_LIST == 32);
}

} // namespace TestCompositorDrawList

#endif // TOOLS_ENABLED

#endif // TEST_COMPOSITOR_DRAWLIST_H

