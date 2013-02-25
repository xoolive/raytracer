Utilisation de git et de github
===============================

### Pour tout le monde

Voir les consignes sur la page [README.md](README.md).

### Pour ceux qui souhaitent utiliser git en tant que système de contrôle de versions.

_Attention!_ Ceci s'adresse *exclusivement* aux étudiants qui sont à l'aise en informatique ! Mieux vaut une bonne livraison classique qu'une mauvaise livraison (problèmes, retards, etc.) avec git. Assurez vos arrières!

Pour vous familiariser avec git, vous trouverez un tutoriel ici :
[http://try.github.com/](http://try.github.com/)

 - Pour publier votre code sur github, d'abord, créez un compte, puis depuis votre répertoire raytracer:
```sh
git remote add rendu https://github.com/<votre-repository-github>
git push -u rendu master
```
Le nom d'utilisateur est l'adresse mail du compte.
Le mot de passe est... votre mot de passe sur github.com

 - Pour garder une trace de la version courante (*commit*)
```sh
git status
git add <les fichiers à ajouter>
git status # (pour vérifier)
git commit -m "Un message explicatif des modifications"
```

 - Pour envoyer vos modifications sur le serveur (dans votre compte):
```sh
git push
```

 - Pour récupérer les modifications depuis le serveur (depuis une autre machine par exemple):
```sh
git pull
```
**Par défaut, git push et git pull travaillent sur *votre* compte github.**

 - Pour récupérer des modifications sur le serveur du professeur:
```sh
git pull origin master
```

 - Commandes pour vérifier:
   - le statut de votre répertoire: ```git status```
   - votre réglage proxy: ```git config http.proxy```
   - votre réglage push par défaut: ```git config branch.master.remote``` (on doit reconnaître votre compte)


### Livraison

Une fois tous ces réglages terminés, vous ferez votre livraison en envoyant au
professeur un e-mail contenant le résultat des deux commandes suivantes:

```sh
git config branch.master.remote
git status
```

Vérifiez bien que:
 - le résultat contient un lien vers *votre* compte github,
 - vous n'avez pas oublié de committer des fichiers (```Changes not staged for commit``` ou ```Changes to be committed```)
 - vous n'avez pas oublié de publier vos modifications (```Your branch is ahead of 'rendu/master' by 1 commit```).




