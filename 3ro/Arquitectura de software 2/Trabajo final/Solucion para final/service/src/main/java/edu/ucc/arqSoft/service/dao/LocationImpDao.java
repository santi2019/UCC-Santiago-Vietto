package edu.ucc.arqSoft.service.dao;

import org.springframework.stereotype.Repository;

import edu.ucc.arqSoft.service.common.dao.GenericDaoImp;
import edu.ucc.arqSoft.service.model.Location;

@Repository
public class LocationImpDao extends GenericDaoImp<Location, Long> implements LocationDao{

}
