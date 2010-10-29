#include "xr_scene_revision.h"
#include "xr_scene_common.h"
#include "xr_reader.h"
#include "xr_writer.h"

using namespace xray_re;

xr_scene_revision::xr_scene_revision(): m_modifier("unknown"), m_modified_time(0) {}

void xr_scene_revision::load(xr_reader& r)
{
	if (r.find_chunk(TOOLS_CHUNK_REVISION)) {
		r.r_sz(m_modifier);
		m_modified_time = r.r_u32();
		r.debug_find_chunk();
	}
}

void xr_scene_revision::save(xr_writer& w) const
{
	w.open_chunk(TOOLS_CHUNK_REVISION);
	w.w_sz(m_modifier);
	w.w_u32(m_modified_time);
	w.close_chunk();
}
