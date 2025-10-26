# Generating documentation
1. Install doxide if not installed: https://doxide.org/installation/

2. Install the uv python package manager: https://docs.astral.sh/uv/getting-started/installation/

3. Generate documentation:
    ```properties
    > doxide build
    > uv run mkdocs build
    ```

4. Preview the documentation by serving locally (Optional):
    ```properties
    > uv run mkdocs serve
    ```