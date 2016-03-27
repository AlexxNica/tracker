executable(
    'tracker-needle',
    'config.vapi',
    'tracker-needle.vala',
    'tracker-history.vala',
    'tracker-needle.vala',
    'tracker-query.vala',
    'tracker-result-store.vala',
    'tracker-stats.vala',
    'tracker-tags-view.vala',
    'tracker-utils.vala',
    'tracker-view.vala',
    dependencies: [tracker_sparql_dep, gtk3],
    c_args: [
        '-DSRCDIR="' + meson.current_source_dir() +'/"',
        '-D_XOPEN_SOURCE',
        '-D_XOPEN_SOURCE_EXTENDED',
        '-include', 'config.h'
    ]
)
