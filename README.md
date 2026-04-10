# Enigma
o decifrador
# Cria as pastas
mkdir src tests docs scripts

# Cria o .gitignore com padrões comuns
cat <<EOF > .gitignore
node_modules/
dist/
build/
.venv/
__pycache__/
.env
*.log
.DS_Store
EOF

# Cria o README profissional
cat <<EOF > README.md
# Projeto Fortaleza (GCO)

Repositório estruturado seguindo boas práticas de Gerência de Configuração.

##  Estrutura de Pastas
- **/src**: Código-fonte.
- **/tests**: Testes unitários e integração.
- **/docs**: Documentação técnica.
- **/scripts**: Automações.

##  Como Executar
1. Clone: \`git clone [URL_DO_REPO]\`
2. Instale: \`npm install\` ou \`pip install -r requirements.txt\`
3. Rode: \`npm start\` ou \`python src/main.py\`

##  Política de Branches
- \`main\`: Código estável e aprovado.
- \`feature/...\`: Novas funcionalidades.
- \`fix/...\`: Correção de bugs.
EOF

# Inicializa o Git e faz o primeiro commit
git init
git add .
git commit -m "chore: setup inicial da estrutura de GCO"

echo " Fortaleza criada com sucesso!"
