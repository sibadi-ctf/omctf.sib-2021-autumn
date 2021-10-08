from waitress import serve
import ppc3
serve(ppc3.app, host='0.0.0.0', port=10007)
