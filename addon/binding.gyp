{
    "targets": [
        {
            "target_name": "lists_addon",
            "sources": [
                "lists_addon.cpp",
                "my_object.cpp"
            ],
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ]
        }
    ]
}