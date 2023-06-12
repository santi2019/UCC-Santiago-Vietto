package edu.ucc.arqSoft.service.dao;

import org.springframework.stereotype.Repository;

import edu.ucc.arqSoft.service.common.dao.GenericDaoImp;
import edu.ucc.arqSoft.service.model.Pelicula;

@Repository
public class PeliculaImpDao extends GenericDaoImp<Pelicula, Long> implements PeliculaDao{

}
