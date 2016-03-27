shared_libtracker_miner_monitor_sources = files('tracker-monitor.c')
shared_libtracker_miner_file_system_sources = files('tracker-file-system.c')
shared_libtracker_miner_crawler_sources = files('tracker-crawler.c')

enums = gnome.mkenums('tracker-miner-enum-types',
    sources: 'tracker-miner-enums.h',
    c_template: 'tracker-miner-enum-types.c.template',
    h_template: 'tracker-miner-enum-types.h.template',
)

private_sources = [
    'tracker-crawler.c',
    'tracker-file-data-provider.c',
    'tracker-file-enumerator.c',
    'tracker-file-notifier.c',
    'tracker-file-system.c',
    'tracker-priority-queue.c',
    'tracker-task-pool.c',
    'tracker-sparql-buffer.c',
    'tracker-thumbnailer.c',
    'tracker-utils.c']

if libmediaart.found()
    private_sources.append(['tracker-media-art.c'])
endif

miner_sources = [
    enums[0], enums[1],
    shared_libtracker_miner_monitor_sources,
    shared_libtracker_miner_file_system_sources,
    shared_libtracker_miner_crawler_sources,
    'tracker-data-provider.c',
    'tracker-decorator.c',
    'tracker-decorator-fs.c',
    'tracker-enumerator.c',
    'tracker-indexing-tree.c',
    'tracker-miner-object.c',
    'tracker-miner-online.c',
    'tracker-miner-fs.c']

libtracker_miner_private = static_library(
    'tracker-miner-private',
    private_sources,
    dependencies: [tracker_common_dep, tracker_sparql_dep],
    c_args: [
        '-DTRACKER_COMPILATION',
    ],
)

tracker_miner_dependencies = []
if network_manager.found()
    tracker_miner_dependencies += network_manager
endif

libtracker_miner = library(
    'tracker-miner-' + tracker_api_version,
    miner_sources,
    link_with: [libtracker_miner_private],
    dependencies: [tracker_common_dep, tracker_sparql_dep] + tracker_miner_dependencies,
    c_args: [
        '-DTRACKER_COMPILATION',
    ],
)

tracker_miner_dep = declare_dependency(
    sources: enums[1],
    link_with: libtracker_miner,
    dependencies: [tracker_common_dep, tracker_sparql_dep],
    include_directories: include_directories('.')
)
