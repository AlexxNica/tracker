libtracker_bus = static_library('tracker-bus',
    'tracker-bus.vala',
    'tracker-namespace.vala',
    'tracker-array-cursor.vala',
    'tracker-bus-fd-cursor.vala',
    '../libtracker-common/libtracker-common.vapi',
    dependencies: [tracker_common_dep, tracker_sparql_intermediate_dep],
    c_args: [
        '-DNO_LIBDBUS',
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

tracker_sparql_bus_dep = declare_dependency(
    link_with: libtracker_bus,
    include_directories: include_directories('.')
)
