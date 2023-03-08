#include "Cjt_estudiants.hh"
#include <algorithm>

Cjt_estudiants::Cjt_estudiants()
{
  imax = -1;
  nest = 0;
  vest = vector<Estudiant>(MAX_NEST);
}

// New methods ----------------------------------------------//
void Cjt_estudiants::recalcular_posicio_imax()
{
  imax = -1;
  double mark_max = -1;
  for (int i = 0; i < nest; ++i)
  {
    if (vest[i].te_nota())
    {
      double temp_mark = vest[i].consultar_nota();
      // if temp_mark is higher or in case of a tie, the lowest DNI
      if (temp_mark > mark_max or (temp_mark == mark_max and (vest[i].consultar_DNI() < vest[imax].consultar_DNI())))
      {
        mark_max = temp_mark;
        imax = i;
      }
    }
  }
}

void Cjt_estudiants::esborrar_estudiant(int dni)
{
  int pos = cerca_dicot(vest, 0, nest - 1, dni);
  for (int i = pos; i < nest - 1; ++i)
  {
    vest[i] = vest[i + 1];
  }
  --nest;
  // if the eliminated student is the imax
  if (pos == imax)
  {
    recalcular_posicio_imax();
  }
  else if (pos < imax)
  {
    // if the eliminated students was before the the imax, we have to decrement the imax position by 1.
    --imax;
  }
}
Estudiant Cjt_estudiants::estudiant_nota_max() const
{
  return vest[imax];
}

// End of new methods -----------------------------------------//

// Modified methods---------------------------------------------//
void Cjt_estudiants::afegir_estudiant(const Estudiant &est)
{
  if (nest >= MAX_NEST)
    throw PRO2Excepcio("Conjunt ple");
  int i = nest - 1;
  bool b = false;
  int dni = est.consultar_DNI();
  while (i >= 0 and not b)
  {
    if (dni > vest[i].consultar_DNI())
      b = true;
    else
    {
      vest[i + 1] = vest[i];
      --i;
    }
  }
  // i es la posicio mes avancada amb el DNI mes petit que dni, si n'hi ha;
  // si no, i=-1
  vest[i + 1] = est;
  ++nest;
  // if there were no students with marks before then the new students, if he has a mark, will be the imax
  if (imax == -1 and vest[i + 1].te_nota())
  {
    imax = i + 1;
  }
  else if (vest[i + 1].te_nota() and imax != -1)
  {
    // if both new and max_mark student has a mark then we have to compare.
    double max_mark = vest[imax].consultar_nota();
    double temp_mark = vest[i + 1].consultar_nota();
    // if the new students was before the imax, then we have to increment imax by 1
    if (i + 1 <= imax)
    {
      ++imax;
      // once we incremented imax, max_mark is not longer the imax student mark.
      if (temp_mark >= vest[imax].consultar_nota())
        imax = i + 1;
    }
    else
    {
      if (temp_mark > max_mark)
        imax = i + 1;
    }
  }
}

void Cjt_estudiants::modificar_estudiant(const Estudiant &est)
{
  /* Pre: existeix un estudiant al parametre implicit amb el dni d'est  */
  int x = est.consultar_DNI();
  int i = cerca_dicot(vest, 0, nest - 1, x);
  vest[i] = est;

  if (i == imax)
    recalcular_posicio_imax();
  else if (imax == -1 and vest[i].te_nota())
    imax = i;
  else if (vest[i].te_nota() and imax != -1)
  {
    double max_mark = vest[imax].consultar_nota();
    double temp_mark = vest[i].consultar_nota();
    if (i < imax)
    {
      if (temp_mark >= max_mark)
        imax = i;
    }
    else
    {
      if (temp_mark > max_mark)
        imax = i;
    }
  }
}

void Cjt_estudiants::modificar_iessim(int i, const Estudiant &est)
{
  if (i < 1 or i > nest)
    throw PRO2Excepcio("Index no valid per a modificar_iessim");
  vest[i - 1] = est;
  --i;
  if (i == imax)
    recalcular_posicio_imax();
  else if (imax == -1 and vest[i].te_nota())
    imax = i;
  else if (vest[i].te_nota() and imax != -1)
  {
    double max_mark = vest[imax].consultar_nota();
    double temp_mark = vest[i].consultar_nota();
    if (i < imax)
    {
      if (temp_mark >= max_mark)
        imax = i;
    }
    else
    {
      if (temp_mark > max_mark)
        imax = i;
    }
  }
}
// End of modified methods-------------------------------------//

int Cjt_estudiants::cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x)
{
  /* Pre: vest esta ordenat */
  int i;
  bool found = false;
  while (left <= right and not found)
  {
    i = (left + right) / 2;
    if (x < vest[i].consultar_DNI())
      right = i - 1;
    else if (x > vest[i].consultar_DNI())
      left = i + 1;
    else
      found = true;
  }
  // i es la posicio, si l'element existeix
  if (found)
    return i;
  else
    return -1;
}

int Cjt_estudiants::mida() const
{
  return nest;
}

int Cjt_estudiants::mida_maxima()
{
  return MAX_NEST;
}

bool Cjt_estudiants::existeix_estudiant(int dni) const
{
  int i = cerca_dicot(vest, 0, nest - 1, dni);
  return (i != -1);
}

Estudiant Cjt_estudiants::consultar_estudiant(int dni) const
{
  int i = cerca_dicot(vest, 0, nest - 1, dni);
  return vest[i];
}

Estudiant Cjt_estudiants::consultar_iessim(int i) const
{
  if (i < 1 or i > nest)
    throw PRO2Excepcio("Index no valid per a consultar_iessim");
  return vest[i - 1];
}

bool comp(const Estudiant &e1, const Estudiant &e2)
{
  return (e1.consultar_DNI() < e2.consultar_DNI());
}

void Cjt_estudiants::ordenar_cjt_estudiants()
{
  sort(vest.begin(), vest.begin() + nest, comp);
}

void Cjt_estudiants::llegir()
{
  cin >> nest;
  if (nest > MAX_NEST)
    throw PRO2Excepcio("El conjunt no pot ser mes gran que la mida maxima");
  for (int i = 0; i < nest; ++i)
    vest[i].llegir();
  ordenar_cjt_estudiants();
  recalcular_posicio_imax();
}

void Cjt_estudiants::escriure() const
{
  for (int i = 0; i < nest; ++i)
    vest[i].escriure();
}
