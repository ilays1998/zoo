from pathlib import Path

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



