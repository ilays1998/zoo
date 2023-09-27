from pathlib import Path
from graphql import build_client_schema, get_introspection_query, print_schema
import requests


from qtgqlcodegen.config import QtGqlConfig
from qtgqlcodegen.types import CustomScalarDefinition

config = QtGqlConfig(graphql_dir=Path(__file__).parent, env_name="Zoo",

                     custom_scalars={
                         "url": CustomScalarDefinition(
                             name='url',
                             graphql_name='url',
                             deserialized_type='QString',
                             to_qt_type='QString',
                             include_path='"../idscalar.hpp"'
                         )
                     }

                     )

res = requests.post("http://127.0.0.1:8000/graphql/", json={"query": get_introspection_query()})
res.raise_for_status()
d = res.json()['data']

client_schema = build_client_schema(d)
schema_file = Path(__file__).parent / "schema.graphql"
schema_file.resolve(True).write_text(print_schema(client_schema))





