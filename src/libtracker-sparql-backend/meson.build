libtracker_sparql = library('tracker-sparql-' + tracker_api_version,
    'tracker-backend.vala',
    dependencies: [tracker_sparql_intermediate_dep, tracker_sparql_remote_dep, tracker_sparql_bus_dep, tracker_sparql_direct_dep],
)
tracker_sparql_dep = declare_dependency(
    link_with: [libtracker_sparql, libtracker_common],
    include_directories: srcinc,
    dependencies: [tracker_common_dep, tracker_sparql_intermediate_dep],
)
