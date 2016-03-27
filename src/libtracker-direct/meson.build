libtracker_direct = static_library('tracker-direct',
    'tracker-direct.vala',
    'tracker-namespace.vala',
    '../libtracker-common/libtracker-common.vapi',
    '../libtracker-data/libtracker-data.vapi',
    '../libtracker-data/tracker-sparql-query.vapi',
    dependencies: [
        tracker_data_dep,
        tracker_sparql_intermediate_dep],
    c_args: [
        '-DTRACKER_COMPILATION',
    ],
    vala_args: [
        '--debug',
        '--pkg', 'posix',
        # FIXME: Meson has code to add --target-glib automatically, but it
        # doesn't seem to work here.
        '--target-glib', glib_required,
    ],
)

tracker_sparql_direct_dep = declare_dependency(
    link_with: libtracker_direct,
    include_directories: include_directories('.')
)
