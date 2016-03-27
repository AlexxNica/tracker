enums_c = gnome.mkenums('tracker-sparql-enum-types',
    sources: 'tracker-notifier.h',
    c_template: 'tracker-sparql-enum-types.c.template',
)
enums_h = gnome.mkenums('tracker-sparql-enum-types',
    sources: 'tracker-notifier.h',
    h_template: 'tracker-sparql-enum-types.h.template',
)

tracker_sparql_intermediate_dependencies = [gio, glib, uuid]

libtracker_sparql_intermediate = static_library('tracker-sparql-' + tracker_api_version,
    enums_c, enums_h,
    'tracker-namespace.vala',
    'tracker-builder.vala',
    'tracker-connection.vala',
    'tracker-cursor.vala',
    'tracker-utils.vala',
    'tracker-namespace-manager.c',
    'tracker-notifier.c',
    'tracker-resource.c',
    'tracker-uri.c',
    'tracker-version.c',
    vala_header: 'tracker-generated.h',
    link_with: [libtracker_common],
    dependencies: [tracker_common_dep] + tracker_sparql_intermediate_dependencies,
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

tracker_sparql_intermediate_dep = declare_dependency(
    link_with: [libtracker_sparql_intermediate],
    include_directories: include_directories('.'),
    dependencies: tracker_sparql_intermediate_dependencies + [
        uuid
    ]
)
