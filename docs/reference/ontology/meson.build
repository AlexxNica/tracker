version_xml = configure_file(input: 'version.xml.in',
    output: 'version.xml',
    configuration: conf)


#for f in `find $ONTOLOGIES_DATA_DIR -name "*.description"` ; do
#    # ../../src/ontologies/XX-aaa.description -> PREFIX=aaa
#    TMPNAME=${f%.description}
#    PREFIX=${TMPNAME#*-}
#    echo "- Generating $PREFIX documentation"
#
#    $TTL2SGML -d $f -o $BUILD_DIR/$PREFIX-ontology.xml \
#        -e $ONTOLOGIES_INFO_DIR/$PREFIX/explanation.xml


gen_doc = meson.source_root() + '/docs/tools/gen-doc.sh'
generated = custom_target('ontology-doc-generated',
    output: 'gen-doc.stamp',
    command: ['false', gen_doc, ttl2sgml, ttlresource2sgml,
              meson.source_root() + '/src/ontologies',
              meson.source_root() + '/docs/ontologies',
              'xml/'],
    depends: [ttl2sgml, ttlresource2sgml],
)
fuckyou = 'nothing'

gnome.gtkdoc('ontology',
    src_dir: '.',
    main_sgml: 'ontology-docs.sgml',
    content_files: [version_xml],
    install: true)
