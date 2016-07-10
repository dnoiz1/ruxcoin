from distutils.core import setup
setup(name='RUXspendfrom',
      version='1.0',
      description='Command-line utility for ruxcoin "coin control"',
      author='Gavin Andresen',
      author_email='gavin@ruxcoinfoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
