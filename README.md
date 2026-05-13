<div align="center">

# Turbo Libft 42

**Une bibliothèque C personnelle, étendue et organisée — bien au-delà de la `libft` standard.**

![Language](https://img.shields.io/badge/Language-C-00599C?style=flat-square&logo=c&logoColor=white)
![Norme](https://img.shields.io/badge/Norme-42-000000?style=flat-square)
![Build](https://img.shields.io/badge/Build-Makefile-427819?style=flat-square)
![Licence](https://img.shields.io/badge/Licence-École_42-blueviolet?style=flat-square)

</div>

---

## Sommaire

- [Présentation](#présentation)
- [Architecture du projet](#architecture-du-projet)
- [Compilation](#compilation)
- [Utilisation](#utilisation)
- [Modules & Fonctions](#modules--fonctions)
- [Cibles du Makefile](#cibles-du-makefile)
- [Conventions](#conventions)
- [Auteur](#auteur)

---

## Présentation

**Turbo Libft 42** est une réimplémentation enrichie de la bibliothèque standard du C, conçue dans le cadre du cursus de l'École 42. Elle reprend l'intégralité des fonctions imposées par le sujet `libft` (partie obligatoire et bonus), tout en y ajoutant un ensemble d'utilitaires personnels — gestion de tableaux, tokenizer, tri, conversions de base, etc. — pour servir de socle commun à tous les projets ultérieurs (`ft_printf`, `get_next_line`, `push_swap`, `minishell`, `cub3d`, ...).

L'objectif : disposer d'une boîte à outils **fiable, normée et organisée par catégorie fonctionnelle**, prête à être linkée dans n'importe quel projet C.

---

## Architecture du projet

Le code est rangé par **responsabilité fonctionnelle**, pas par ordre alphabétique. Chaque dossier correspond à une famille cohérente d'opérations :

```
Turbo_Libft_42/
├── allocs/         → Allocation, copie et libération mémoire
├── comparers/      → Comparaison de mémoire et de chaînes
├── converters/     → Conversions ASCII / numériques / casse
├── is_dirs/        → Prédicats de classification de caractères
├── iter_on_ft/     → Itérateurs avec callback
├── lists/          → Listes chaînées (partie bonus)
├── printers/       → Écriture sur descripteur de fichier
├── searchers/      → Recherche dans mémoire / chaînes / tableaux
├── sizers/         → Calcul de longueur et de taille
├── sorters/        → Algorithmes de tri
├── splitters/      → Découpage, concaténation, sous-chaînes
├── Makefile        → Compilation, nettoyage, recompilation
└── libft.h         → Header public (à inclure dans vos projets)
```

> **Note** : les objets `.o` sont générés dans un dossier `objects/` miroir afin de garder l'arborescence des sources propre.

---

## Compilation

### Prérequis

- `gcc` ou `cc` compatible C99
- `make`
- `ar` (inclus avec `binutils`)

### Construire la bibliothèque

```bash
make
```

La compilation produit `libft.a` à la racine du projet. Les drapeaux utilisés sont :

```
-Wall -Wextra -Werror -g3
```

---

## Utilisation

### 1. Linker dans votre projet

```bash
cc -Wall -Wextra -Werror main.c -L./Turbo_Libft_42 -lft -o my_program
```

### 2. Inclure le header

```c
#include "libft.h"
```

### 3. Exemple minimal

```c
#include "libft.h"

int main(void)
{
    char    **tokens;
    char    *joined;

    tokens = ft_split("Hello,42,World", ',');
    joined = ft_strjoin(tokens[0], tokens[2]);
    ft_putendl_fd(joined, 1);

    free(joined);
    free_split(tokens);
    return (0);
}
```

---

## Modules & Fonctions

### `allocs/` — Mémoire

| Fonction          | Rôle                                            |
| :---------------- | :---------------------------------------------- |
| `ft_bzero`        | Met à zéro un bloc mémoire                      |
| `ft_calloc`       | Allocation initialisée à zéro                   |
| `ft_memcpy`       | Copie mémoire sans recouvrement                 |
| `ft_memmove`      | Copie mémoire avec recouvrement géré            |
| `ft_memset`       | Remplit un bloc avec un octet donné             |
| `ft_strdup`       | Duplique une chaîne                             |
| `ft_strndup`      | Duplique les `n` premiers caractères            |
| `ft_tabdup`       | Duplique un tableau de chaînes                  |
| `free_split`      | Libère un tableau retourné par `ft_split`       |

### `comparers/` — Comparaisons

| Fonction      | Rôle                                  |
| :------------ | :------------------------------------ |
| `ft_memcmp`   | Compare deux blocs mémoire            |
| `ft_strncmp`  | Compare deux chaînes sur `n` octets   |

### `converters/` — Conversions

| Fonction        | Rôle                                            |
| :-------------- | :---------------------------------------------- |
| `ft_atoi`       | Chaîne → entier                                 |
| `ft_atoi_base`  | Chaîne → entier dans une base arbitraire        |
| `ft_itoa`       | Entier → chaîne                                 |
| `ft_tolower`    | Caractère en minuscule                          |
| `ft_toupper`    | Caractère en majuscule                          |

### `is_dirs/` — Prédicats sur caractères

| Fonction       | Rôle                          |
| :------------- | :---------------------------- |
| `ft_isalnum`   | Lettre ou chiffre             |
| `ft_isalpha`   | Lettre                        |
| `ft_isascii`   | Caractère ASCII (0–127)       |
| `ft_isdigit`   | Chiffre                       |
| `ft_isprint`   | Caractère imprimable          |
| `ft_isspace`   | Espace blanc                  |

### `iter_on_ft/` — Itérateurs

| Fonction        | Rôle                                                |
| :-------------- | :-------------------------------------------------- |
| `ft_striteri`   | Applique une fonction à chaque caractère (in-place) |
| `ft_strmapi`    | Applique une fonction à chaque caractère (copie)    |

### `lists/` — Listes chaînées (bonus)

| Fonction               | Rôle                                       |
| :--------------------- | :----------------------------------------- |
| `ft_lstnew`            | Crée un nouveau maillon                    |
| `ft_lstadd_front`      | Ajoute en tête                             |
| `ft_lstadd_back`       | Ajoute en queue                            |
| `ft_lstdelone`         | Supprime un maillon                        |
| `ft_lstclear`          | Vide entièrement la liste                  |
| `ft_lstlast`           | Renvoie le dernier maillon                 |
| `ft_lstsize`           | Nombre de maillons                         |
| `ft_lstiter`           | Applique une fonction à chaque maillon     |
| `ft_lstmap`            | Mappe une fonction et crée une nouvelle liste |

### `printers/` — Sortie

| Fonction          | Rôle                                       |
| :---------------- | :----------------------------------------- |
| `ft_putchar_fd`   | Écrit un caractère sur un fd               |
| `ft_putstr_fd`    | Écrit une chaîne sur un fd                 |
| `ft_putendl_fd`   | Écrit une chaîne suivie d'un saut de ligne |
| `ft_putnbr_fd`    | Écrit un entier sur un fd                  |
| `print_tab`       | Affiche un tableau de chaînes              |

### `searchers/` — Recherche

| Fonction      | Rôle                                                |
| :------------ | :-------------------------------------------------- |
| `ft_memchr`   | Recherche un octet dans un bloc mémoire             |
| `ft_strchr`   | Première occurrence d'un caractère                  |
| `ft_strrchr`  | Dernière occurrence d'un caractère                  |
| `ft_strnstr`  | Recherche d'une sous-chaîne bornée                  |
| `ft_tabchr`   | Recherche d'une chaîne dans un tableau              |

### `sizers/` — Mesures

| Fonction     | Rôle                                       |
| :----------- | :----------------------------------------- |
| `ft_strlen`  | Longueur d'une chaîne                      |
| `tab_size`   | Taille d'un tableau de chaînes             |
| `tablen`     | Variante de comptage de tableau            |

### `sorters/` — Tri

| Fonction          | Rôle                                |
| :---------------- | :---------------------------------- |
| `sort_alpha_tab`  | Tri alphabétique d'un tableau       |
| `sort_str_tab`    | Tri de chaînes selon un critère     |

### `splitters/` — Découpage & assemblage

| Fonction        | Rôle                                                |
| :-------------- | :-------------------------------------------------- |
| `ft_split`      | Découpe une chaîne selon un séparateur              |
| `ft_strtok`     | Tokenizer style libc                                |
| `ft_substr`     | Extrait une sous-chaîne                             |
| `ft_strjoin`    | Concatène deux chaînes (alloue le résultat)         |
| `ft_strlcpy`    | Copie de chaîne sécurisée et bornée                 |
| `ft_strlcat`    | Concaténation sécurisée et bornée                   |
| `ft_strtrim`    | Supprime les caractères de bord                     |

---

## Cibles du Makefile

| Cible      | Description                                              |
| :--------- | :------------------------------------------------------- |
| `all`      | Compile `libft.a` (cible par défaut)                     |
| `clean`    | Supprime les fichiers objets (`objects/`)                |
| `fclean`   | `clean` + suppression de `libft.a`                       |
| `re`       | `fclean` puis `all`                                      |

La compilation est **silencieuse** et **colorée** : chaque étape (compilation, linkage, nettoyage) est annoncée par un message ANSI lisible.

---

## Conventions

- **Norme 42** respectée intégralement (`norminette` clean).
- Code écrit en **C99**, sans avertissement avec `-Wall -Wextra -Werror`.
- Pas de variable globale, pas de fonction interdite.
- Toutes les fonctions allouant de la mémoire **renvoient `NULL` en cas d'échec** et **n'effectuent pas de fuites**.
- Le header `libft.h` expose **uniquement** les prototypes destinés à un usage externe.

---

## Auteur

**Thomas Robert** — `throbert`
Étudiant à l'École **42**

Pour toute remarque, suggestion ou amélioration : ouvrez une *issue* ou faites une *pull request*.

---

<div align="center">

*« Coder, c'est comme écrire : la rigueur sert la clarté, la clarté sert la lecture. »*

</div>
