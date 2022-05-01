file(REMOVE_RECURSE
  "libmain_header.pdb"
  "libmain_header.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/main_header.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
